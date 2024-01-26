<?php

declare(strict_types=1);

use Bastard\Framework\Settings\Settings;
use Bastard\Framework\Settings\SettingsInterface;
use DI\ContainerBuilder;
use Monolog\Logger;

return function (ContainerBuilder $containerBuilder) {
    /** @TODO Implement the Dotenv library and load environment specific configuration settings */

    // Global Settings Object
    $containerBuilder->addDefinitions([
        SettingsInterface::class => function () {
            return new Settings([
                'displayErrorDetails' => true, // Should be set to false in production
                'logError'            => false,
                'logErrorDetails'     => false,
                'logger' => [
                    'name' => 'slim-app',
                    'path' => isset($_ENV['docker']) ? 'php://stdout' : __DIR__ . '/../logs/app.log',
                    'level' => Logger::DEBUG,
                ],
                // The View Layer Settings
                'view' => [
                    'template_paths' => [
                        'default' => __DIR__ . '/../templates/main',
                    ],
                    'asset_paths' => [
                        'default' => __DIR__ . '/../assets'
                    ],
                ],
                // Determines details about the Website
                'siteDetails' => [
                    'title' => 'The Bastard Framework',
                    'description' => 'A small Framework made from Slim and Plates.',
                    'tags' => implode(',', ['framework', 'php', 'slimphp', 'plates']),
                ],
            ]);
        }
    ]);
};
