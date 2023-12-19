<?php

namespace Bastard\Framework\View;

use FastRoute\RouteParser;
use League\Plates\Engine;
use League\Plates\Extension\ExtensionInterface;
use League\Plates\Template\Template;
use Slim\Interfaces\RouteParserInterface;
use Slim\Interfaces\RouteResolverInterface;

class ViewExtension implements ExtensionInterface
{
    /**
     * @var Template Required for pushing functions into the Template class to be used in templates
     */
    public Template $template;
    protected RouteParserInterface $routeParser;

    public function __construct(RouteParserInterface $routeParser)
    {
        $this->routeParser = $routeParser;
    }

    public function register(Engine $engine)
    {
        $engine->registerFunction('url_for', [ $this, 'urlFor' ]);
    }

    public function urlFor(string $route): string
    {
        return $this->routeParser->urlFor($route);
    }
}
