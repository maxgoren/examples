#!/usr/bin/perl
use 1.0;
my @unsorted;
my @result;
@unsorted = qw(A S O R T I N G E X A M P L E);
print "original array: \n";
&printArr(@unsorted);
print "\nBubble Sort: \n";
&bubbleSort(@unsorted);

print "\n\noriginal array: \n";
&printArr(@unsorted);
print "\nSelection Sort: \n";
&selectionSort(@unsorted);

print "\n\noriginal array: ";
&printArr(@unsorted);
print "\nInsertion Sort: \n";
&insertionSort(@unsorted);

sub printArr {
  my (@arr) = @_;
  foreach (@arr) {
    print $_ . " ";
  }
  print "\n";
}

sub bubbleSort {
    my (@unsorted) = @_;
    my ($i, $j, $tmp);
    for ($i = 0; $i < $#unsorted; $i++)
    {
        for ($j = $i+1; $j <= $#unsorted; $j++)
        {
            if ($unsorted[$j] lt $unsorted[$i])
            {
                $tmp = $unsorted[$i];
                $unsorted[$i] = $unsorted[$j];
                $unsorted[$j] = $tmp;
            }
        }
        printArr(@unsorted);
    }
    return @unsorted;
}

sub selectionSort {
  my (@unsorted) = @_;
  my ($i, $j, $smallest, $tmp);
  for ($i = 0; $i < $#unsorted; $i++)
  {
    $smallest = $j;
    for ($j = $i + 1; $j < $#unsorted; $j++)
    {
        if ($unsorted[$j] lt $unsorted[$smallest]) {
            $smallest = $j;
        }
    }
    if ($unsorted[$smallest] lt $unsorted[$i]) {
      $tmp = $unsorted[$i]; 
      $unsorted[$i] = $unsorted[$smallest];
      $unsorted[$smallest] = $tmp;
      printArr(@unsorted);
    }
  }
  return @unsorted;
}

sub insertionSort {
    my (@unsorted) = @_;
    my ($i, $j, $v, $tmp);
    for ($i = 2; $i <= $#unsorted; $i++)
    {
        $j = $i;
        $v = $unsorted[$j];
        while ($unsorted[$j - 1] gt $v)
        {
            $unsorted[$j] = $unsorted[$j-1];
            $j--;
        }
        $unsorted[$j] = $v;
        printArr(@unsorted);
    }
    return @unsorted;
}