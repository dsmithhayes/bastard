<?php

namespace Bastard\Framework;

use League\Plates\Engine;
use Psr\Http\Message\ResponseInterface as Response;
use Psr\Http\Message\ServerRequestInterface as Request;
use Slim\Routing\RouteContext;

abstract class Controller
{
    protected Request $request;
    protected Response $response;
    protected RouteContext $route;
    protected Engine $view;
    protected array $args;

    public function __construct(Engine $view)
    {
        $this->view = $view;
    }

    /**
     * @param Request $request
     * @param Response $response
     * @param array $args
     * @return Response
     */
    public function __invoke(Request $request, Response $response, array $args): Response
    {
        $this->request = $request;
        $this->response = $response;
        $this->args = $args;
        $this->route = RouteContext::fromRequest($this->request);

        return $this->action();
    }

    /**
     * Each Controller that inherits from this base-class will need to implement some form of Action.
     * @return Response
     */
    abstract public function action(): Response;

    /**
     * Render the Template given and send back the Response object.
     * @param string $template
     * @param array $data
     * @return Response
     */
    public function render(string $template, array $data = []): Response
    {
        $this->response->getBody()->write($this->view->render($template, $data));
        return $this->response->withHeader('Content-Type', 'text/html');
    }

    /**
     * @param string $routeName
     * @param int $status
     * @return Response
     */
    public function redirect(string $routeName, int $status = 301): Response
    {
        $route = $this->route->getRouteParser()->urlFor($routeName);
        return $this->response->withHeader('Location', $route)->withStatus($status);
    }

    /**
     * @param array $data
     * @param string $contentType
     * @return Response
     */
    public function respondWithData(array $data, string $contentType = 'application/json'): Response
    {
        $response = $this->response->withHeader('Content-Type', $contentType);
        $response->getBody()->write(json_encode($data));
        return $response;
    }
}
