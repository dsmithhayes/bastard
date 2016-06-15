<?hh

namespace Bastard;

use Bastard\Http\RequestInterface;
use Bastard\Http\ResponseInterface;

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3
 */

newtype ResponseCallback = (function(RequestInterface, ResponseInterface): ResponseInterface);

class Bastard
{
    private static Map<string, ResponseCallback> $getRoutes;

    private static Map<string, ResponseCallback> $postRoutes;

    private static Map<string, ResponseCallback> $putRoutes;

    private static Map<string, ResponseCallback> $patchRoutes;

    private static Map<string, ResponseCallback> $deleteRoutes;

    private static Map<string, ResponseCallback> $optionsRoutes;

    public function get(string $route, ResponseCallback $callback): void
    {
        $this->getRoutes[$route] = $callback;
    }

    public function post(string $route, ResponseCallback $callback): void
    {
        $this->postRoutes[$route] = $callback;
    }

    public function put(string $route, ResponseCallBack $callback): void
    {
        $this->putRoutes[$route] = $callback;
    }

    public function patch(string $route, ResponseCallback $callback): void
    {
        $this->patchRoutes[$route] = $callback;
    }

    public function delete(string $route, ResponseCallback $callback): void
    {
        $this->deleteRoutes[$route] = $callback;
    }

    public function options(string $route, ResponseCallback $callback): void
    {
        $this->optionsRoutes[$route] = $callback;
    }
}
