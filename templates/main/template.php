<!DOCTYPE html>
<html lang="en">
    <head>
        <title><?= $this->e($title); ?></title>
        <meta name="description" content="<?= $this->e($description); ?>" />
        <meta name="tags" content="<?= $this->e($tags); ?>" />
        <style>
            * {
                margin: 0;
                padding: 0;
            }
            body {
                background-color: #eeeeee;
            }
            .container {
                background-color: #ffffff;
                width: 100%;
                max-width: 1200px;
                margin: 1em auto;
                padding: 1em;
                border: 1px solid #333333;
            }
            header, footer {
                margin-top: 0.5em;
                margin-bottom: 0.5em;
            }
            header hr {
                margin-bottom: 1em;
            }
            footer hr {
                margin-top: 1em;
            }
        </style>
    </head>
    <body>
        <div class="container">
            <header>
                <div>Bastard</div>
                <hr />
            </header>

            <main>
                <?= $this->section('content'); ?>
            </main>

            <footer>
                <hr />
                <div>&copy; 2023</div>
            </footer>
        </div>

    </body>
</html>
