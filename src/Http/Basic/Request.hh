<?hh

namespace Bastard\Http\Basic;

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3.0
 */

use Bastard\Http\RequestInterface;

class Request implements RequestInterface
{
    private Map<string, string> $headers;
    private string $method;

    /**
     * Rips information out of the $_SERVER super global
     */
    public function __construct()
    {
        $this->headers = Map{

        };

        $this->method = 'GET';
    }

    public function getHeaders(): Map<string, string>
    {
        return $this->headers;
    }

    public function getHeader(string $key): string
    {
        return $this->headers[$key];
    }

    public function setHeader(Map<string, string> $header): this
    {
        $this->headers->setAll($header);
        return $this;
    }

    public function getMethod(): string
    {
        return $this->method;
    }

    public function setMethod(string $method): this
    {
        $this->method = $method;
        return $this;
    }
}
