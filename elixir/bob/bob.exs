defmodule Bob do
  def empty?(input) do
    String.strip(input) == ""
  end

  def shouting?(input) do
    String.upcase(input) != String.downcase(input) && String.upcase(input) == input
  end

  def question?(input) do
    String.ends_with?(input, "?")
  end

  def hey(input) do
    cond do
      empty?(input) ->
        "Fine. Be that way!"
      question?(input) && shouting?(input) ->
        "Calm down, I know what I'm doing!"
      question?(input) ->
        "Sure."
      shouting?(input) ->
        "Whoa, chill out!"
      true ->
        "Whatever."
    end
  end
end
