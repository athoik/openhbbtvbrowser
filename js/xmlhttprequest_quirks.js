window.cefXmlHttpRequestQuirk = function(uri) {
  // Start 1.
  //    Das Erste + ...

  // The URL contains sid as decimal value, but hex value is needed
  let sid = /(getapp\.php\?sid=)(.*?)(&colid=.*?&query=appid)/.exec(uri);

  if (sid) {
      // change sid[2] to hex
      sid[2] = Number(sid[2]).toString(16);
      return sid[1] + sid[2] + sid[3];
  }
  // End 1.


  // return unchanged URL
  return uri;
}

window.alert = function alert(message) {
  // alert is breaking openhbbtv, override to console.info
  console.info('[ALERT]: ' + message);
}

window.addEventListener('load', function() {
  //check if we are on ert.gr and try to fix menu up/down
  if (window.location.href.indexOf(".ert.gr") > -1) {
    console.info('[MENUFIX] Trying to fix double key up/down move in ert.gr');
    document.removeEventListener(GLOBALS.keyevent, GLOBALS.keyeventlistener, false);
    GLOBALS.keyeventlistener = function (e) {
      if(!e.isTrusted && (e.keyCode == VK_DOWN||e.keyCode == VK_UP)) return;
      if (GLOBALS.demomode && (e.ctrlKey || e.altKey || e.metaKey)) return;
      var kc = e.keyCode, handled;
      if (!kc) kc = e.charCode;
      handled = GLOBALS.focusmgr.handleKeyCode(kc);
      if (handled) e.preventDefault();
      return handled;
    }
    document.addEventListener(GLOBALS.keyevent, GLOBALS.keyeventlistener, false);
  }
});
