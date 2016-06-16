<?hh

namespace Bastard\Http;

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3.0
 */

interface ResponseInterface
{
    /**
     * @return int
     *      The status code of the response
     */
    public function getCode(): int;

    /**
     * @param int $code
     *      The status code of the response
     */
    public function setCode(int $code): this;

    /**
     * @return string
     *      The response body
     */
    public function getBody(): string;

    /**
     * @param string $body
     *      New response body to set
     */
    public function setBody(string $body): this;
}
