<!DOCTYPE html>  
<html>  
<body>  
<?php
$rows = $_GET['size'];
$cols = $_GET['size'];
echo "<table border=\"1\">";
        echo '<tr>';
        for ($i=0; $i <= $cols; $i++)
        {
        if ($i == 0)
        {
            echo '<td></td>';
        }
        else
        {
            echo '<td>' .$i.'</td>';
        }
        }
        for ($r =1; $r <= $rows; $r++)
        {
            echo'<tr>';
            echo '<td>'.$r. '</td>';
            for ($c = 1; $c <= $cols; $c++)
            {
                echo '<td>' .$c*$r.'</td>';
            }
            echo '</tr>';
        }

  echo"</table>";
?>    
</table>  
</body>  
</html>  