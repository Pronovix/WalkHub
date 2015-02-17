if (!jQuery.fn.addBack) {
  jQuery.fn.addBack = function (selector) {
    if (typeof selector !== "string") {
      return this.andSelf();
    }
    else {
      return this.andSelf().filter(selector);
    }
  };
}
