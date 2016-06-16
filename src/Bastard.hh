<?hh // strict

namespace Bastard;

use Bastard\Http\RequestInterface;
use Bastard\Http\ResponseInterface;
use Bastard\Http\Dispatcher;

newtype ResponseCallback = (function(RequestInterface, ResponseInterface): ResponseInterface);

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3
 */

class Bastard
{
    private static ?Map<string, ResponseCallback> $getRoutes;
    private static ?Map<string, ResponseCallback> $postRoutes;
    private static ?Map<string, ResponseCallback> $putRoutes;
    private static ?Map<string, ResponseCallback> $patchRoutes;
    private static ?Map<string, ResponseCallback> $deleteRoutes;
    private static ?Map<string, ResponseCallback> $optionsRoutes;

    private static ?RequestInterface $request;
    private static ?ResponseInterface $response;

    private ?Dispatcher $dispatcher;

    public function get(string $route, ResponseCallback $callback): this
    {
        if (!self::$getRoutes) {
            self::$getRoutes = Map{$route => $callback};
        } else {
            self::$getRoutes->set($route, $callback);
        }

        return $this;
    }

    public function post(string $route, ResponseCallback $callback): this
    {
        if (!self::$postRoutes) {
            self::$postRoutes = Map{ $route => $callback };
        } else {
            self::$postRoutes->set($route, $callback);
        }

        return $this;
    }

    public function put(string $route, ResponseCallback $callback): this
    {
        if (!self::$putRoutes) {
            self::$putRoutes = Map{ $route => $callback };
        } else {
            self::$putRoutes->set($route, $callback);
        }

        return $this;
    }

    public function patch(string $route, ResponseCallback $callback): this
    {
        if (!self::$patchRoutes) {
            self::$patchRoutes = Map{ $route => $callback };
        } else {
            self::$patchRoutes->set($route, $callback);
        }

        return $this;
    }

    public function delete(string $route, ResponseCallback $callback): this
    {
        if (!self::$deleteRoutes) {
            self::$deleteRoutes = Map{ $route => $callback };
        } else {
            self::$deleteRoutes->set($route, $callback);
        }

        return $this;
    }

    public function options(string $route, ResponseCallback $callback): this
    {
        if (!self::$optionsRoutes) {
            self::$optionsRoutes = Map{ $route => $callback };
        } else {
            self::$optionsRoutes->set($route, $callback);
        }

        return $this;
    }

    public function run(RequestInterface $request, ResponseInterface $response): void
    {
        if (!is_null(self::$getRoutes)) {
            foreach (self::$getRoutes as $route => $callback) {
                $callback($request, $response);
            }
        }
    }
}
