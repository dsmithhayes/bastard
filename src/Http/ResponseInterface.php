<?hh

namespace Bastard\Http;

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3
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
    public function setCode(int $code): void;

    public function getBody(): string;
    public function setBody(string $body): void;
}
