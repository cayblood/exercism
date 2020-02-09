# frozen_string_literal: true

# Write your code for the 'Resistor Color Duo' exercise in this file. Make the tests in
# `resistor_color_duo_test.rb` pass.
#
# To get started with TDD, see the `README.md` file in your
# `ruby/resistor-color-duo` directory.

class ResistorColorDuo
  COLORS = %w[black brown red orange yellow green blue violet grey white].freeze

  def self.value(colors)
    sum = 0
    place = 1
    colors[0, 2].reverse_each do |color|
      sum += COLORS.index(color) * place
      place *= 10
    end
    sum
  end
end
