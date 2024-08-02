<?php

    // configuration
    require("../includes/config.php");

    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO

        if ($_POST["username"] == NULL)
        {
            apologize("You must enter a username");
        }
        
        else if ($_POST["password"] == NULL)
        {
            apologize("You must enter a password");
        }
        
        else if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Your password and password confirmation don't match");
        }
        
        if (query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"])) === false)
        {
            apologize("Sorry, that username has already been taken!");
            
        }
        
        else
        {
            $rows = query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            $_SESSION["id"] = $id;
            redirect("index.php");
        }
    }
    else
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

?>
