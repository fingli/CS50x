<?php

    // configuration
    require("../includes/config.php"); 

    // if form is submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST") 
    {
        // if deposit amount is invalid (not a whole positive integer)
        if (preg_match("/^\d+$/", $_POST["deposit"]) == false)
        {
            // apologize
            apologize("You must enter a whole, positive integer.");
        }

        // set transaction type
        $transaction = 'ADD';
        $shares = 1;
        
        // update user's cash
        query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["deposit"], $_SESSION["id"]);
        
        // update history
        query("INSERT INTO history (id, transaction, shares, price) VALUES (?, ?, ?, ?)", $_SESSION["id"], $transaction, $shares, $_POST["deposit"]);
        
        // redirect to portfolio 
        redirect("/");
    }
    
    // if form hasn't been submitted
    else
    {
        // render portfolio (pass in new portfolio table and cash)
        render("deposit_form.php", ["title" => "Deposit Form"]);
    }

?>
