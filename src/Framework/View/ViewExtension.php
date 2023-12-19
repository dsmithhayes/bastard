<?php

namespace Bastard\Framework\View;

use FastRoute\RouteParser;
use League\Plates\Engine;
use League\Plates\Extension\ExtensionInterface;
use League\Plates\Template\Template;
use Psr\Http\Message\UriInterface;
use Slim\Interfaces\RouteParserInterface;
use Slim\Interfaces\RouteResolverInterface;

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

    public function __construct(RouteParserInterface $routeParser, UriInterface $uri, string $basePath = '')
    {
        $this->routeParser = $routeParser;
        $this->uri = $uri;
        $this->basePath = $basePath;
    }

    public function register(Engine $engine)
    {
        $this->engine = $engine;
        $engine->registerFunction('url_for', [ $this, 'urlFor' ]);
    }

    public function urlFor(string $name, array $data = [], array $queryParams = []): string
    {
        return $this->routeParser->urlFor($name, $data, $queryParams);
    }

    public function fullUrlFor(string $name, array $data = [], array $queryParams = []): string
    {
        return $this->routeParser->fullUrlFor($this->uri, $name, $data, $queryParams);
    }
}
