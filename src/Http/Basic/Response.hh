<?hh // strict

namespace Bastard\Http\Basic;

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3.0
 */

use Bastard\Http\ResponseInterface;

/**
 * This is a basic implementation of the \Bastard\Http\ResponseInterface which
 * is used by default in the framework.
 */
class Response implements ResponseInterface
{
    /**
     * Map of all the HTTP headers to send back to the client.
     */
    private ?Map<string, string> $headers;

    /**
     * The response code, by default this will always be 200.
     */
    private int $code = 200;

    /**
     * The response body, by default this is an empty string.
     */
    private string $body = '';

    public function getCode(): int
    {
        return $this->code;
    }

    public function setCode(int $code): this
    {
        $this->code = $code;
        return $this;
    }

    public function getBody(): string
    {
        return $this->body;
    }

    public function setBody(string $body): this
    {
        $this->body = $body;
        return $this;
    }

    /**
     * Sets a specific header to return to the client
     */
    public function setHeader(Map<string, string> $header): this
    {

        return $this;
    }

    public function respond(): void
    {

    }
}
