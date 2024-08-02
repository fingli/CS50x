        
<?php require("../cs50/templates/header.php"); ?>

        <div class="navbar navbar-fixed-top">
            <div class="navbar-inner">
                <div class="container">
                    <a class="brand" href="/">CS50x Final Project</a>
                    <div class="nav-collapse collapse">
                        <ul class="nav">
                            <li><a href="/">Home</a></li>
                            <li class="active"><a href="search.php">Search</a></li>
                            <li><a href="portfolio.php">Portfolio</a></li>
                            <li><a href="contact.php">Contact</a></li>
                        </ul>
                    </div><!--/.nav-collapse -->
                </div>
            </div>
        </div>
        
    <h1><span style="color:#0063DC;">Flickr</span><span style="color:#FF0084;">Pickr</span></h1>
        <h4>CS50 Edition</h4>
    <br />
    <br />
        <h4>Enter a username to search for</h4>

    <form method="post" class="form-search">
        <div class="input-append">
            <input autofocus placeholder="Username" type="text" class="span2 search-query" name="username">
            <button type="submit" class="btn">Search</button>
        </div>
    </form>
  
<?php
require_once("../cs50/includes/phpFlickr/phpFlickr.php");
// Create new phpFlickr object
$f = new phpFlickr("570ad86ae513416bd72ad5e068c9a315");
 
//$i = 0;
if (!empty($_POST['username']))
{
	// Find the NSID of the username inputted via the form
    $person = $f->people_findByUsername($_POST['username']);
 
    // Get the friendly URL of the user's photos
    $photos_url = $f->urls_getUserPhotos($person['id']);
 
    // Get the user's first 12 public photos
    $photos = $f->people_getPublicPhotos($person['id'], NULL, NULL, 12);
    
    echo "<h3>Photos from: '$_POST[username]'</h3>";
    echo "<ul class='thumbnails'>";
    
    // Loop through the photos and output the html
    foreach ((array)$photos['photos']['photo'] as $photo)
    {
        echo "<li class='span3'><div class='thumbnail'>";
        echo "<a href=$photos_url$photo[id] target='_blank' >";
        echo "<img alt='$photo[title]' title='$photo[title]' ".
            "src=" . $f->buildPhotoURL($photo, "Small") . ">";
        echo "</a>";
        echo "<h5>$photo[title]</h5>";
        echo "</div></li>";
        //$i++;
        // If it reaches the fourth photo, insert a line break
        //if ($i % 4 == 0) {
            //echo "<br />";
        //}
    }
    echo "</ul>";
}
?>
 
<?php require("../cs50/templates/footer.php"); ?>   
