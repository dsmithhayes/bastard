<?hh

namespace Bastard\Http;

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes>
 * @license BSD 3
 */

class Dispatcher
{
    public function __construct(
        private RequestInterface  $request,
        private ResponseInterface $response
    ) { }

    /**
     * Matches a route to a defined ResponseCallback
     */
    public function matchRoute(string $route)
    {

    }

    public function dispatch()
    {

    }
}
