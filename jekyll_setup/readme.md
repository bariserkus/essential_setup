* If an error occurs when installing wdm, try this

gem install wdm -- --with-cflags=-Wno-implicit-function-declaration

Also add this to Gemfile:

gem 'wdm', '>= 0.1.0' if Gem.win_platform?

or 

gem "wdm", "~> 0.1.1", :install_if => Gem.win_platform?

* Serve the web page:

bundle exec jekyll serve --watch --incremental