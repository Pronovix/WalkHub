environment = :production

css_dir = "css"
sass_dir = "sass"

output_style = (environment == :development) ? :expanded : :compact

relative_assets = true

sass_options = (environment == :development) ? {:debug_info => false} : {:always_update => true}
