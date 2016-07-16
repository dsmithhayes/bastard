<?hh // strict

namespace Bastard;

use Bastard\Http\Basic\Request;
use Bastard\Http\Basic\Response;
use Bastard\Http\Dispatcher;

/**
 * Defines the callback method that takes in a Request and a Response object
 * that then returns the Response object.
 */
newtype ResponseCallback = (function(Request, Response): Response);

/**
 * Defines the Route map which will be a URI string and optionally a
 * ResponseCallback type.
 */
newtype Route = Map<string, ?ResponseCallback>;

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3
 */

class Bastard
{
    /**
     * Map of all the routes and callbacks defined for the application.
     */
    private Map<string, Route> $routes = Map{
        'GET'    => Map{ '/' => null },
        'POST'   => Map{ '/' => null },
        'PUT'    => Map{ '/' => null },
        'PATCH'  => Map{ '/' => null },
        'DELETE' => Map{ '/' => null },
        'OPTION' => Map{ '/' => null }
    };

    /**
     * Implements Bastard\Http\RequestInterface
     */
     private Request $request;

    /**
     * Implements Bastard\Http\ResponseInterface
     */
    private Response $response;

    /**
     * Instance of the Bastard\Dispatcher
     */
    private Dispatcher $dispatcher;

    public function __construct(Request $request, Response $response)
    {
        $this->request    = $request;
        $this->response   = $response;
        $this->dispatcher = new Dispatcher();
    }

    public function get(string $route, ResponseCallback $callback): this
    {
        $this->routes->set('GET', Map{ $route => $callback });
        return $this;
    }

    public function post(string $route, ResponseCallback $callback): this
    {
        $this->routes->set('POST', Map{ $route => $callback });
        return $this;
    }

    public function put(string $route, ResponseCallback $callback): this
    {
        $this->routes->set('PUT', Map{ $route => $callback });
        return $this;
    }

    public function patch(string $route, ResponseCallback $callback): this
    {
        $this->routes->set('PATCH', Map{ $route => $callback });
        return $this;
    }

    public function delete(string $route, ResponseCallback $callback): this
    {
        $this->routes->set('DELETE', Map{ $route => $callback });
        return $this;
    }

    public function options(string $route, ResponseCallback $callback): this
    {
        $this->routes->set('OPTIONS', Map{ $route => $callback });
        return $this;
    }

    /**
     * Sets a common route and callback to multiple HTTP methods.
     */
    public function set(string           $route,
                        Set<string>      $methods,
                        ResponseCallback $callback): this
    {
        foreach ($methods as $method) {
            if ($this->validMethod(($method))) {
                $this->routes->set($method, Map{$route => $callback});
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
        // check request for the method

        // match the route

        // run the callback
    }

    /**
     * Assures that the method trying to be accessed from the develop is a
     * valid HTTP method supported by Bastard
     */
    private function validMethod(string $method): bool
    {
        return $this->routes->containsKey($method);
    }
}
