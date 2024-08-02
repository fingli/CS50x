<div class="navbar">
    <div class="navbar-inner">
        <ul class="nav">
            <li><a href="index.php">Portfolio</a></li>
            <li class="active"><a href="quote.php">Quote</a></li>
            <li><a href="buy.php">Buy</a></li>
            <li><a href="sell.php">Sell</a></li>
            <li><a href="history.php">History</a></li>
            <li><a href="deposit.php">Deposit</a></li>
            <li><a href="logout.php"><strong><span style="color: crimson">Log Out</span></strong></a></li>
        </ul>
    </div>
</div>

<form action="quote.php" method="post">
    <fieldset>
        <div class="control-group">
            <input autofocus name="symbol" placeholder="Symbol" type="text"/>
        </div>
        <div class="control-group">
            <button type="submit" class="btn">Get Quote</button>
        </div>
    </fieldset>
</form>
