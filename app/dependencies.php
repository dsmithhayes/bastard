<?php

declare(strict_types=1);

use Bastard\Framework\Settings\SettingsInterface;
use DI\ContainerBuilder;
use League\Plates\Engine;
use League\Plates\Template\Theme;
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

            $engine = Engine::fromTheme(Theme::hierarchy([
                Theme::new($settings['template_paths']['default'], 'Main'),
                // Add more themes here
            ]));

            // Add the global data into the Engine
            $siteDetails = $c->get(SettingsInterface::class)->get('siteDetails');
            $engine->addData([
                'title' => $siteDetails['title'],
                'tags' => $siteDetails['tags'],
                'description' => $siteDetails['description'],
            ]);

            return $engine;
        }
    ]);
};
