<?hh

namespace Bastard\Http;

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3
 */

interface RequestInterface
{
    /**
     * @return Map<string, string>
     *      The list of all headers sent to the server in the request
     */
    public function getHeaders(): Map<string, string>;

    /**
     * @param string $key
     *      The key of the header to get
     * @return string
     *      The value of the header
     */
    public function getHeader(string $key): string;

    /**
     * @return string
     *      The request method
     */
    public function getMethod(): string;

    /**
     * @param string $method
     *      Sets the request method, usually takend from
     *      $_SERVER['REQUEST_METHOD']
     */
    public function setMethod(string $method): void;
}
