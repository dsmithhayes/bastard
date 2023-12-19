<?php

declare(strict_types=1);

use Bastard\Framework\Settings\SettingsInterface;
use DI\ContainerBuilder;
use League\Plates\Engine;
use Monolog\Handler\StreamHandler;
use Monolog\Logger;
use Monolog\Processor\UidProcessor;
use Psr\Container\ContainerInterface;
use Psr\Log\LoggerInterface;

return function (ContainerBuilder $containerBuilder) {
    $containerBuilder->addDefinitions([
        LoggerInterface::class => function (ContainerInterface $c) {
            $settings = $c->get(SettingsInterface::class);

            $loggerSettings = $settings->get('logger');
            $logger = new Logger($loggerSettings['name']);

            $processor = new UidProcessor();
            $logger->pushProcessor($processor);

            $handler = new StreamHandler($loggerSettings['path'], $loggerSettings['level']);
            $logger->pushHandler($handler);

            return $logger;
        },
        Engine::class => function (ContainerInterface $c) {
            $settings = $c->get(SettingsInterface::class)->get('view');
            $engine = new Engine($settings['template_paths']['default']);

            // Add more template paths here

            return $engine;
        }
    ]);
};
