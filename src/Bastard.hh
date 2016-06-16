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

    public function get(string $route, ResponseCallback $callback): void
    {
        self::$getRoutes = Map{
            $route => $callback
        };
    }

    public function post(string $route, ResponseCallback $callback): void
    {
        self::$postRoutes = Map{
            $route => $callback
        };
    }

    public function put(string $route, ResponseCallback $callback): void
    {
        self::$putRoutes = Map{
            $route => $callback
        };
    }

    public function patch(string $route, ResponseCallback $callback): void
    {
        self::$patchRoutes = Map{
            $route => $callback
        };
    }

    public function delete(string $route, ResponseCallback $callback): void
    {
        self::$deleteRoutes = Map{
            $route => $callback
        };
    }

    public function options(string $route, ResponseCallback $callback): void
    {
        self::$optionsRoutes = Map{
            $route => $callback
        };
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
