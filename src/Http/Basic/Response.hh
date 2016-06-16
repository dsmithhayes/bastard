<?hh // strict

namespace Bastard\Http\Basic;

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3.0
 */

use Bastard\Http\ResponseInterface;

class Response implements ResponseInterface
{
    private ?Map<string, string> $headers;
    private int    $code = 200;
    private string $body = '';

    public function __construct()
    {

    }

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
}
