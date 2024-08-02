<?php

    // configuration
    require("../includes/config.php"); 

    // query user's portfolio
    $rows = query("SELECT * FROM portfolios WHERE id = ?", $_SESSION["id"]);

    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name"   => $stock["name"],
                "symbol" => $row["symbol"],
                "price"  => $stock["price"],
                "shares" => $row["shares"],
                "total"  => $row["shares"] * $stock["price"]
            ];
        }
    }

    // user's cash for template
    $user = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);

    // render portfolio
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio", "user" => $user]);

?>
