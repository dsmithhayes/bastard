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
     * @param Map<string, string> $header
     *
     */
    public function setHeader(Map<string, string> $header): this;

    /**
     * @return string
     *      The request method
     */
    public function getMethod(): string;

    /**
     * @param string $method
     *      Sets the request method
     */
    public function setMethod(string $method): this;
}
