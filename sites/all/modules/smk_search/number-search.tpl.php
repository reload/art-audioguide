<?php
/**
 * @file
 * The template file for the Number-Search markup.
 */
?>
<div class="number-pad">
  <!-- Display -->
  <div class="display">
    <a href="#" class="clear"></a>

    <div class="placeholder">
      <div class="inner">
        <?php print $intro; ?>
        <br>
        <?php print $example; ?> <span class="audio-id">123</span>
      </div>
    </div>

    <div class="audio-id-value"></div>
  </div>

  <!-- Keys -->
  <nav class="keys">
    <ul>
      <li><a class="key key-number key-seven" href="#"><span>7</span></a></li>
      <li><a class="key key-number key-eight" href="#"><span>8</span></a></li>
      <li><a class="key key-number key-nine last" href="#"><span>9</span></a></li>

      <li><a class="key key-number key-four" href="#"><span>4</span></a></li>
      <li><a class="key key-number key-five" href="#"><span>5</span></a></li>
      <li><a class="key key-number key-six last" href="#"><span>6</span></a></li>

      <li><a class="key key-number key-one" href="#"><span>1</span></a></li>
      <li><a class="key key-number key-two" href="#"><span>2</span></a></li>
      <li><a class="key key-number key-three last" href="#"><span>3</span></a></li>

      <li><a class="key key-backspace bottom" href="#"><span></span></a></li>
      <li><a class="key key-number key-zero bottom" href="#"><span>0</span></a></li>
      <li><input type="submit" value="ok" class="key key-submit last bottom"></li>
    </ul>
  </nav>

  <!-- Help -->
  <div class="help">
    <?php print $help; ?>
  </div>
</div>
