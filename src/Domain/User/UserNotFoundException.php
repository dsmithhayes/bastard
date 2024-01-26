<?php

declare(strict_types=1);

namespace Bastard\Domain\User;

use Bastard\Domain\DomainException\DomainRecordNotFoundException;

class UserNotFoundException extends DomainRecordNotFoundException
{
    public $message = 'The user you requested does not exist.';
}
