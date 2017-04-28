<!DOCTYPE html>
<html>
<body>

<style>
form {
    display: inline;

}
</style>
 <form>
		<input type="button" onclick="myFunction()" value="Convert "/>
	</form>
	<form action="" method="post" enctype="multipart/form-data">
    	<input type="file" name="file" id="file" onChange="this.form.submit();">
	</form> 

<?php
$dir = "files/";
echo ("<br>");

// Open a directory, and read its contents
if (is_dir($dir))
{
  if ($dh = opendir($dir))
  {
    while (($file = readdir($dh)) !== false)
    {
      $array[] = $file;
    }
    closedir($dh);
    foreach($array as $value)
    {
    	if (strpos($value, ".txt") == true || strpos($value, ".html") == true)
    	{
    		if (strpos($value, ".info") == false)
    		{
    			echo "<a href=files/$value>$value</a><br>";
    		}
    	}
    }
  }
}
if ($_FILES["file"]["error"] > 0)
{
    //echo "Return Code: " . $_FILES["file"]["error"] . "<br />";
}
else
{
    //echo "Upload: " . $_FILES["file"]["name"] . "<br />";
    //echo "Type: " . $_FILES["file"]["type"] . "<br />";
    //echo "Size: " . ($_FILES["file"]["size"] / 1024) . " Kb<br />";
    //echo "Temp file: " . $_FILES["file"]["tmp_name"] . "<br />";

    if (file_exists("files/" . $_FILES["file"]["name"]))
    {
        //echo $_FILES["file"]["name"] . " already exists. ";
    }
    else
    {

        if (move_uploaded_file($_FILES["file"]['tmp_name'],
        "files/" . $_FILES["file"]["name"]))
        {
      	    //echo "Stored in: " . "files/" . $_FILES["file"]["name"];
      	    echo "<meta http-equiv='refresh' content='0'>";
        }
        else
        {
        	//echo $_FILES['file']['error'];
        }
    }
}
?>


<script>
function myFunction()
{
    //alert("This is convert botton"); // this is the message in ""
    //alert(document.write("<h1>This is a heading</h1>"));
    var x;
    if (confirm("Press a button!") == true) {
        x = "You pressed OK!";
    } else {
        x = "You pressed Cancel!";
    }
    document.getElementById("demo").innerHTML = x;
}
</script>



</body>
</html> 