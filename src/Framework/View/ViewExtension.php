<?php

namespace Bastard\Framework\View;

use League\Plates\Engine;
use League\Plates\Extension\ExtensionInterface;
use League\Plates\Template\Template;
use Psr\Http\Message\UriInterface;
use Slim\Interfaces\RouteParserInterface;

class ViewExtension implements ExtensionInterface
{
    /**
     * @var Template Required for pushing functions into the Template class to be used in templates
     */
    public Template $template;
    protected UriInterface $uri;
    protected string $basePath;
    protected Engine $engine;
    protected RouteParserInterface $routeParser;

    /**
     * @param RouteParserInterface $routeParser
     * @param UriInterface $uri
     * @param string $basePath
     */
    public function __construct(RouteParserInterface $routeParser, UriInterface $uri, string $basePath = '')
    {
        $this->routeParser = $routeParser;
        $this->uri = $uri;
        $this->basePath = $basePath;
    }

    /**
     * @param Engine $engine
     * @return void
     */
    public function register(Engine $engine)
    {
        $this->engine = $engine;
        $this->engine->registerFunction('url_for', [ $this, 'urlFor' ]);
        $this->engine->registerFunction('full_url_for', [ $this, 'fullUrlFor' ]);
    }

    /**
     * @param string $name
     * @param array $data
     * @param array $queryParams
     * @return string
     */
    public function urlFor(string $name, array $data = [], array $queryParams = []): string
    {
        return $this->routeParser->urlFor($name, $data, $queryParams);
    }

    /**
     * @param string $name
     * @param array $data
     * @param array $queryParams
     * @return string
     */
    public function fullUrlFor(string $name, array $data = [], array $queryParams = []): string
    {
        return $this->routeParser->fullUrlFor($this->uri, $name, $data, $queryParams);
    }
}
