project('prosody', 'vala', 'c')

dependencies = [
    dependency('json-glib-1.0'),
    dependency('gee-0.8'),
    dependency('libsoup-3.0'),
    meson.get_compiler('vala').find_library('posix'),
    dependency('libxml-2.0'),
]

prosody = ['parser', 'lib', 'data', 'expression', 'writers', 'loader',
        'slice']
prosody_misc = ['json', 'http', 'diff', 'i18n', 'tsv', 'xml', 'test',
        'AppStream', 'mimeinfo', 'I18nUtil']
sources = []
foreach f : prosody
    sources += [f]
endforeach
foreach f : prosody_misc
    sources += ['misc/' + f]
endforeach

source_files = []
foreach f : sources
    source_files += files(f + '.vala')
endforeach

prosody_lib = static_library('prosody', source_files, dependencies : dependencies)
prosody_dep = declare_dependency(
    link_with : prosody_lib,
    include_directories : include_directories('.')
)