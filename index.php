<?hh

require 'vendor/autoload.php';

use \Bastard\Bastard;
use \Bastard\Http\Basic\Request;
use \Bastard\Http\Basic\Response;

$bastard = new Bastard();

$bastard->get('/', function (Request $req, Response $res) {
    echo "You made it!";
    return $res;
});

$bastard->run();
