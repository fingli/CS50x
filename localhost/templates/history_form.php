<div class="navbar">
    <div class="navbar-inner">
        <ul class="nav">
            <li><a href="index.php">Portfolio</a></li>
            <li><a href="quote.php">Quote</a></li>
            <li><a href="buy.php">Buy</a></li>
            <li><a href="sell.php">Sell</a></li>
            <li class="active"><a href="history.php">History</a></li>
            <li><a href="deposit.php">Deposit</a></li>
            <li><a href="logout.php"><strong><span style="color: crimson">Log Out</span></strong></a></li>
            </ul>
    </div>
</div>

<table class="table table-striped">
    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>

    <tbody>
    
        <?php foreach ($table as $row): ?>
        <tr>
            <td><?php echo $row["transaction"] ?></td>
            <td><?php echo date('d/m/y, g:i a', strtotime($row["time"])) ?></td>
            <td><?php echo $row["symbol"] ?></td>            
            <td><?php echo $row["shares"] ?></td>
            <td>$<?php echo number_format($row["price"], 2) ?></td>          
        </tr>
        <?php endforeach ?> 

        <tr>
            <td colspan="4"><strong>CASH</strong></td>
            <td style="background: orange">$<?php echo number_format($user[0]["cash"], 2) ?></td>
        </tr>

    </tbody>
    
</table>
