<?php

namespace Bastard\Framework\View;

use League\Plates\Engine;
use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Server\MiddlewareInterface;
use Psr\Http\Server\RequestHandlerInterface;
use Slim\App;
use Slim\Interfaces\RouteParserInterface;

class ViewExtensionMiddleware implements MiddlewareInterface
{
    protected Engine $engine;
    protected RouteParserInterface $routeParser;

    public function __construct(Engine $engine, RouteParserInterface $routeParser)
    {
        $this->engine = $engine;
        $this->routeParser = $routeParser;
    }

    public static function createFromContainer(App $app)
    {
        $engine = $app->getContainer()->get(Engine::class);
        $routeParser = $app->getRouteCollector()->getRouteParser();

        return new self($engine, $routeParser);
    }

    public function process(ServerRequestInterface $request, RequestHandlerInterface $handler): ResponseInterface
    {
        $this->engine->loadExtension(new ViewExtension($this->routeParser, $request->getUri()));
        return $handler->handle($request);
    }
}
