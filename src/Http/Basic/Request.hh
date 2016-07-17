<?hh

namespace Bastard\Http\Basic;

/**
 * @author  Dave Smith-Hayes <me@davesmithhayes.com>
 * @license BSD 3.0
 */

use Bastard\Http\RequestInterface;

class Request implements RequestInterface
{
    /**
     * The following constants define the HTTP Request methods
     */
    const METHOD_GET     = 'GET';
    const METHOD_POST    = 'POST';
    const METHOD_PUT     = 'PUT';
    const METHOD_PATCH   = 'PATCH';
    const METHOD_DELETE  = 'DELETE';
    const METHOD_OPTIONS = 'OPTIONS';

    /**
     * Built out from the `$_SERVER` superglobal
     */
    private Map<string, string> $headers;

    /**
     * The method requested to the server with.
     */
    private string $method;

    /**
     * Rips information out of the $_SERVER super global
     */
    public function __construct()
    {
        $this->headers = new Map($_SERVER);
        $this->method = $_SERVER['REQUEST_METHOD'];
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
