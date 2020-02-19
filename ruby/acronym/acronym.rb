=begin
Write your code for the 'Acronym' exercise in this file. Make the tests in
`acronym_test.rb` pass.

To get started with TDD, see the `README.md` file in your
`ruby/acronym` directory.
=end

class Acronym
  def self.abbreviate(str)
    words = str.split(/[\W-]+/)
    words.map {|w| w[0].capitalize }.join
  end
end
