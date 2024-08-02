<div class="navbar">
    <div class="navbar-inner">
        <ul class="nav">
            <li><a href="index.php">Portfolio</a></li>
            <li><a href="quote.php">Quote</a></li>
            <li><a href="buy.php">Buy</a></li>
            <li class="active"><a href="sell.php">Sell</a></li>
            <li><a href="history.php">History</a></li>
            <li><a href="deposit.php">Deposit</a></li>
            <li><a href="logout.php"><strong><span style="color: crimson">Log Out</span></strong></a></li>
        </ul>
    </div>
</div>

<form action="sell.php" method="post">
    <fieldset>
        <div class="control-group">
            <select name="symbol">
                <option value=''></option>
                <?php
                    foreach ($stocks as $symbol)
                    {
                        echo("<option value='$symbol'>" . $symbol . "</option>");
                    }
                ?>
            </select>
        </div>
        <div class="control-group">
            <button type="submit" class="btn">Sell</button>
        </div>
    </fieldset>
</form>
