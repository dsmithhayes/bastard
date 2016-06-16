<?hh

require 'vendor/autoload.php';

use \Bastard\Bastard;
use \Bastard\Http\RequestInterface as Request;
use \Bastard\Http\ResponseInterface as Response;

$bastard = new Bastard();

$bastard->get('/', function (RequestInterface $req, ResponseInterface $res) {
    echo "You made it!";
    return $res;
});

$bastard->run();
