<?hh

namespace Bastard\Http;

/**
 * @author Dave Smith-Hayes <me@davesmithhayes.com>
 */

/**
 * Defines methods that will be used to grab information from the request to
 * the server.
 */
interface RequestInterface
{
    /**
     * @return array
     *      The list of all headers sent to the server in the request
     */
    public function getHeaders(): array;

    /**
     * @param string $key
     *      The key of the header to get
     * @return string
     *      The value of the header
     */
    public function getHeader(string $key): string;
}
