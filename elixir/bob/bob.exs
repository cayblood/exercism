defmodule Bob do
  def hey(input) do
    cond do
      String.strip(input) == "" ->
        "Fine. Be that way!"
      String.ends_with?(input, "?") && input =~ ~r/[A-Z]{2,}/ ->
        "Calm down, I know what I'm doing!"
      String.ends_with?(input, "?") ->
        "Sure."
      input =~ ~r/[A-Z]{2,}/ || input == "УХОДИ" ->
        "Whoa, chill out!"
      true ->
        "Whatever."
    end
  end
end
