<?hh

require 'vendor/autoload.php';

use \Bastard\Bastard;
use \Bastard\Http\RequestInterface as Request;
use \Bastard\Http\ResponseInterface as Response;

// implement your own Request and Response, or use the Basic Bastard HTTP
$bastard = new Bastard();

$bastard
    ->get('/', function (Request $req, Response $res): Response {
        echo "You made it!";
        return $res;
    })
    ->get('/hello', function (Request $req, Response $res): Response {
        echo "Welcome home!";
        return $res;
    });

$bastard->run();
