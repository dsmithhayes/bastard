<?hh

require 'vendor/autoload.php';

use \Bastard\Bastard;
use \Bastard\Http\Basic\Request;
use \Bastard\Http\Basic\Response;

// implement your own Request and Response, or use the Basic Bastard HTTP
$bastard = new Bastard(new Request(), new Response());

$bastard->get('/', function (Request $req, Response $res): Response {
    echo "You made it!";
    return $res;
});

$bastard->run();
