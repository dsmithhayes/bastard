<?php

namespace Bastard\Application\Controllers;

use Bastard\Framework\Controller;
use Psr\Http\Message\ResponseInterface as Response;

class HomePageController extends Controller
{
    public function action(): Response
    {
        return $this->render('home');
    }
}
