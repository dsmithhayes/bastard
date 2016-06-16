<?hh // strict

namespace Bastard\Http\Basic;

/**
 * @author  Dave Smith-Hayes
 * @license BSD 3
 */

use Bastard\Http\ResponseInterface;

class Response implements ResponseInterface
{
    private ?Map<string, string> $headers;
    private int $code = 200;
    private string $body = '';

    public function __construct()
    {

    }

    public function getCode(): int
    {
        return $this->code;
    }

    public function setCode(int $code): void
    {
        $this->code = $code;
    }

    public function getBody(): string
    {
        return $this->body;
    }

    public function setBody(string $body): void
    {
        $this->body = $body;
    }
}
