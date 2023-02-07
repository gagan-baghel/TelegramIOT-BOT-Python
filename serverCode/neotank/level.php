<?php
if(!empty($_GET))
{
		//Open Door
		$data = $_GET['level'];
		$fn = "level.txt";
		$fp = fopen($fn, 'w');
		$fw = fwrite($fp,$data);
}
    //Read Door Status
    $fn = "level.txt";
	$fr = fopen($fn, 'r'); 
	$fs = filesize($fn); 
	$level = fread($fr, $fs);
    echo $level;
?>