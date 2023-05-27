.PHONY: pdf clean

input_file = task.asciidoc
output_file = output.pdf

pdf:
	asciidoctor-pdf -a allow-uri-read=true $(input_file) -o $(output_file)

clean:
	rm -f $(output_file)

