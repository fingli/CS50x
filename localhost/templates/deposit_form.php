<div class="navbar">
    <div class="navbar-inner">
        <ul class="nav">
            <li><a href="index.php">Portfolio</a></li>
            <li><a href="quote.php">Quote</a></li>
            <li><a href="buy.php">Buy</a></li>
            <li><a href="sell.php">Sell</a></li>
            <li><a href="history.php">History</a></li>
            <li class="active"><a href="deposit.php">Deposit</a></li>
            <li><a href="logout.php"><strong><span style="color: crimson">Log Out</span></strong></a></li>
        </ul>
    </div>
</div>

<form action="deposit.php" method="post">
    <fieldset>
        <div class="control-group">
            <input class="input-medium" name="deposit" placeholder="Amount of cash" type="text"/>
        </div>
        <div class="control-group">
            <button type="submit" class="btn">Deposit</button>
        </div>
    </fieldset>
</form>
