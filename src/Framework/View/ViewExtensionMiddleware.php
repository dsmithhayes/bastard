<?php

namespace Bastard\Framework\View;

use League\Plates\Engine;
use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Server\MiddlewareInterface;
use Psr\Http\Server\RequestHandlerInterface;
use Slim\Routing\RouteContext;

class ViewExtensionMiddleware implements MiddlewareInterface
{
    public function process(ServerRequestInterface $request, RequestHandlerInterface $handler): ResponseInterface
    {
        $routeParser = RouteContext::fromRequest($request)->getRouteParser();
        $viewExtension = new ViewExtension($routeParser);

        $request->withAttribute('view', $viewExtension);

        return $handler->handle($request);
    }
}