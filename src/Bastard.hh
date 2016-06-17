<?hh // strict

namespace Bastard;

use Bastard\Http\RequestInterface  as Request;
use Bastard\Http\ResponseInterface as Response;
use Bastard\Http\Dispatcher;

newtype ResponseCallback = (function(Request, Response): Response);

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3
 */

class Bastard
{
    /**
     * Map of all the routes and callbacks defined for the application.
     */
    private static Map<string, ?Map<string, ResponseCallback>> $routes = Map{
        'get'     => null,
        'post'    => null,
        'put'     => null,
        'patch'   => null,
        'delete'  => null,
        'options' => null
    };

    private ImmMap<string, string> $methods = ImmMap{
        'GET'     => 'get',
        'POST'    => 'post',
        'PUT'     => 'put',
        'PATCH'   => 'patch',
        'DELETE'  => 'delete',
        'OPTIONS' => 'options'
    };

    /**
     * Implements Bastard\Http\RequestInterface
     */
    private Request  $request;

    /**
     * Implements Bastard\Http\ResponseInterface
     */
    private Response $response;

    /**
     * Instance of the Bastard\Dispatcher
     */
    private ?Dispatcher $dispatcher;

    public function __construct(Request $request, Response $response)
    {
        $this->request  = $request;
        $this->response = $response;
    }

    public function get(string $route, ResponseCallback $callback): this
    {
        self::$routes['get'] = Map{ $route => $callback };
        return $this;
    }

    public function post(string $route, ResponseCallback $callback): this
    {
        self::$routes['post'] = Map{ $route => $callback };
        return $this;
    }

    public function put(string $route, ResponseCallback $callback): this
    {
        self::$routes['put'] = Map{ $route => $callback };
        return $this;
    }

    public function patch(string $route, ResponseCallback $callback): this
    {
        self::$routes['patch'] = Map{ $route => $callback };
        return $this;
    }

    public function delete(string $route, ResponseCallback $callback): this
    {
        self::$routes['delete'] = Map{ $route => $callback };
        return $this;
    }

    public function set(string           $route,
                        Set<string>      $methods,
                        ResponseCallback $callback): this
    {
        foreach ($methods as $method) {
            if ($this->validMethod(($method))) {
                self::$routes[$method] = Map{$route => $callback};
            }
        }

        return $this;
    }

    /**
     * The main entry point of any Bastard application. This should be called
     * at the end of the index.php file that acts at the front controller.
     */
    public function run(): void
    {
        // THROW ALL THE ERRORS NOW.
        
        // check request for the method

        // match the route

        // run the callback
    }

    private function validMethod(string $method): bool
    {
        foreach ($this->methods as $m) {
            if ($method === $m) {
                return true;
            }
        }

        return false;
    }
}
