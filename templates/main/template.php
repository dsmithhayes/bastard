<!DOCTYPE html>
<html lang="en">
    <head>
        <title>Bastard - <?= $this->e($title); ?></title>
    </head>
    <body>
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
    </body>
</html>
