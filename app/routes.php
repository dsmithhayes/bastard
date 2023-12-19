<?php

declare(strict_types=1);

use Bastard\Application\Controllers\HomePageController;
use Psr\Http\Message\ResponseInterface as Response;
use Psr\Http\Message\ServerRequestInterface as Request;
use Slim\App;

return function (App $app) {
    $app->options('/{routes:.*}', function (Request $request, Response $response) {
        // CORS Pre-Flight OPTIONS Request Handler
        return $response;
    });

    /**
     * Homepage Controller Actions
     */
    $app->get('/', HomePageController::class)->setName('home');
};
