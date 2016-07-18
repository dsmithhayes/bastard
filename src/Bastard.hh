<?hh // strict

namespace Bastard;

use Bastard\Http\Basic\Request;
use Bastard\Http\Basic\Response;
use Bastard\Dispatcher;

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
        Request::METHOD_GET     => Map{ '/' => null },
        Request::METHOD_POST    => Map{ '/' => null },
        Request::METHOD_PUT     => Map{ '/' => null },
        Request::METHOD_PATCH   => Map{ '/' => null },
        Request::METHOD_DELETE  => Map{ '/' => null },
        Request::METHOD_OPTIONS => Map{ '/' => null }
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

    public function __construct()
    {
        $this->request    = new Request();
        $this->response   = new Response();
        $this->dispatcher = new Dispatcher();
    }

    /**
     * Adds a route and a method to a specific GET request.
     */
    public function get(string $route, ResponseCallback $callback): this
    {
        $this->routes->at(Request::METHOD_GET)
                     ->add(Pair{ $route, $callback });
        return $this;
    }

    /**
     * Adds a route and a method to a specific POST request.
     */
    public function post(string $route, ResponseCallback $callback): this
    {
        $this->routes->at(Request::METHOD_POST)
                     ->add(Pair{ $route, $callback });
        return $this;
    }

    /**
     * Adds a route and a method to a specific PUT request.
     */
    public function put(string $route, ResponseCallback $callback): this
    {
        $this->routes->at(Request::METHOD_PUT)
                     ->add(Pair{ $route, $callback });
        return $this;
    }

    /**
     * Adds a route and a method to a specific PATCH request.
     */
    public function patch(string $route, ResponseCallback $callback): this
    {
        $this->routes->at(Request::METHOD_PATCH)
                     ->add(Pair{ $route, $callback });
        return $this;
    }

    /**
     * Adds a route and method to a specific DELETE request.
     */
    public function delete(string $route, ResponseCallback $callback): this
    {
        $this->routes->at(Request::METHOD_DELETE)
                     ->add(Pair{ $route, $callback });
        return $this;
    }

    /**
     * Adds a route and a method to a specific OPTIONS request.
     */
    public function options(string $route, ResponseCallback $callback): this
    {
        $this->routes->at(Request::METHOD_OPTIONS)
                     ->add(Pair{ $route, $callback });
        return $this;
    }

    /**
     * Sets a common route and callback to multiple HTTP methods.
     */
    public function set(string $route,
                        Set<string> $methods,
                        ResponseCallback $callback): this
    {
        foreach ($methods as $method) {
            if ($this->routes->containsKey($method)) {
                $this->routes->at($method)->add(Pair{ $route, $callback });
            }
        }

        return $this;
    }

    /**
     * The main entry point of any Bastard application. This should be called
     * at the end of the index.php file that acts at the front controller. This
     * method will make ample usage of the Dispatcher object.
     */
    public function run(): string
    {
        // check request for the method

        // match the route

        // run the callback
        $callback = $this->routes->at($this->request->getMethod())
                                 ->get($this->request->getHeader('REQUEST_URI'));

        if (!is_null($callback)) {
            $this->response = $callback($this->request, $this->response);
        } else {
            echo "500 Error\n";
        }

        return $this->response->respond();
        /*
        foreach ($this->routes as $method => $route) {
            foreach ($route as $r => $c) {
                if (!is_null($c)) {
                    $this->response = $c($this->request, $this->response);
                }
            }
        }
        */
    }

    public function getAllRoutes(): Map<string, Route>
    {
        return $this->routes;
    }

    public function getRoute(string $method): Map<string, ?ResponseCallback>
    {
        return $this->routes->at($method);
    }

    public function getRequest(): Request
    {
        return $this->request;
    }

    public function getResponse(): Response
    {
        return $this->response;
    }
}
